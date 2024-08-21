/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdarg.h>

#include "ds3231.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DS3231_I2C_DEV_ADDR 0x68
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
DS3231_I2C_DEVICE_DEFINE(clock_chip, "DS3231")
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
uint8_t debug_buf[100];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */
static EMBEDD_RESULT ds3231_bus_write(const struct embedd_device_t* dev, const uint8_t* data_ptr, uint32_t data_size);
static EMBEDD_RESULT ds3231_bus_read(const struct embedd_device_t* dev, uint8_t* data_ptr, uint32_t data_size);

static void debug(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
static embedd_bus_t ds3231_bus = {
    .write = ds3231_bus_write,
    .read = ds3231_bus_read
};
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  /* Assign the I2C bus object to the device object */
  clock_chip.bus = &ds3231_bus;

  /* Configure the I2C device settings for the DS3231 */
  embedd_i2c_dev_cfg_t clock_chip_cfg = {.addr = DS3231_I2C_DEV_ADDR};
  embedd_i2c_set_dev_config(&clock_chip, &clock_chip_cfg);

  /* Clear the time keeping registers */
  uint8_t reg_value = 0;
   if (DS3231_WRITE_REG( clock_chip, ds3231_seconds,      reg_value ) == EMBEDD_RESULT_OK &&
       DS3231_WRITE_REG( clock_chip, ds3231_minutes,      reg_value ) == EMBEDD_RESULT_OK &&
       DS3231_WRITE_REG( clock_chip, ds3231_hour,         reg_value ) == EMBEDD_RESULT_OK &&
       DS3231_WRITE_REG( clock_chip, ds3231_day,          reg_value ) == EMBEDD_RESULT_OK &&
       DS3231_WRITE_REG( clock_chip, ds3231_date,         reg_value ) == EMBEDD_RESULT_OK &&
       DS3231_WRITE_REG( clock_chip, ds3231_monthcentury, reg_value ) == EMBEDD_RESULT_OK &&
       DS3231_WRITE_REG( clock_chip, ds3231_year,         reg_value ) == EMBEDD_RESULT_OK)
    {
        debug("Clock has been successfully reset\r\n");
    }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    uint8_t seconds_reg         = 0;
    uint8_t minutes_reg         = 0;
    uint8_t hour_reg            = 0;
    uint8_t day_reg             = 0;
    uint8_t date_reg            = 0;
    uint8_t monthcentury_reg    = 0;
    uint8_t year_reg            = 0;
    uint8_t alarm_1_seconds_reg = 0;
    uint8_t alarm_1_minutes_reg = 0;
    uint8_t alarm_1_hour_reg    = 0;
    uint8_t alarm_1_daydate_reg = 0;
    uint8_t alarm_2_minutes_reg = 0;
    uint8_t alarm_2_hour_reg    = 0;
    uint8_t alarm_2_daydate_reg = 0;
    uint8_t control_reg         = 0;
    uint8_t status_reg          = 0;
    uint8_t aging_offset_reg    = 0;
    uint8_t msb_of_temp_reg     = 0;
    uint8_t lsb_of_temp_reg     = 0;

    // Read all registers
    if (DS3231_READ_REG( clock_chip, ds3231_seconds,         seconds_reg )         == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_minutes,         minutes_reg )         == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_hour,            hour_reg )            == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_day,             day_reg )             == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_date,            date_reg )            == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_monthcentury,    monthcentury_reg )    == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_year,            year_reg )            == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_alarm_1_seconds, alarm_1_seconds_reg ) == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_alarm_1_minutes, alarm_1_minutes_reg ) == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_alarm_1_hour,    alarm_1_hour_reg )    == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_alarm_1_daydate, alarm_1_daydate_reg ) == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_alarm_2_minutes, alarm_2_minutes_reg ) == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_alarm_2_hour,    alarm_2_hour_reg )    == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_alarm_2_daydate, alarm_2_daydate_reg ) == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_control,         control_reg )         == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_status,          status_reg )          == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_aging_offset,    aging_offset_reg )    == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_msb_of_temp,     msb_of_temp_reg )     == EMBEDD_RESULT_OK &&
        DS3231_READ_REG( clock_chip, ds3231_lsb_of_temp,     lsb_of_temp_reg )     == EMBEDD_RESULT_OK)
    {
      /* USER CODE BEGIN IN CASE OF SUCCESS */
      debug("Register map:\r\n");
      debug("  SECONDS           - 0x%02X\r\n", seconds_reg);
      debug("  MINUTES           - 0x%02X\r\n", minutes_reg);
      debug("  HOUR              - 0x%02X\r\n", hour_reg);
      debug("  DAY               - 0x%02X\r\n", day_reg);
      debug("  DATE              - 0x%02X\r\n", date_reg);
      debug("  MONTH_CENTURY     - 0x%02X\r\n", monthcentury_reg);
      debug("  YEAR              - 0x%02X\r\n", year_reg);
      debug("  ALARM_1_SECONDS   - 0x%02X\r\n", alarm_1_seconds_reg);
      debug("  ALARM_1_MINUTES   - 0x%02X\r\n", alarm_1_minutes_reg);
      debug("  ALARM_1_HOUR      - 0x%02X\r\n", alarm_1_hour_reg);
      debug("  ALARM_2_MINUTES   - 0x%02X\r\n", alarm_2_minutes_reg);
      debug("  ALARM_2_HOUR      - 0x%02X\r\n", alarm_2_hour_reg);
      debug("  ALARM_2_DAY_DATE  - 0x%02X\r\n", alarm_2_daydate_reg);
      debug("  CONTROL           - 0x%02X\r\n", control_reg);
      debug("  STATUS            - 0x%02X\r\n", status_reg);
      debug("  AGING_OFFSET      - 0x%02X\r\n", aging_offset_reg);
      debug("  TEMPERATURE_MSB   - 0x%02X\r\n", msb_of_temp_reg);
      debug("  TEMPERATURE_LSB   - 0x%02X\r\n", lsb_of_temp_reg);
      /* USER CODE END IN CASE OF SUCCESS */
    }
    else
    {
      /* USER CODE BEGIN IN CASE OF ERROR */
      debug("Registers reading error!\r\n");
      /* USER CODE END IN CASE OF ERROR */
    }
    HAL_Delay(5000); // Wait 5 seconds before reading again
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00303D5B;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart2, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart2, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_GREEN_Pin */
  GPIO_InitStruct.Pin = LED_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED_GREEN_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
EMBEDD_RESULT ds3231_bus_write(const struct embedd_device_t* dev, const uint8_t* data_ptr, uint32_t data_size)
{
  if( ( dev == NULL ) || ( data_ptr == NULL ) )
  {
    return EMBEDD_RESULT_ERR;
  }

  //Extracting I2C configurations from the device object
  embedd_i2c_dev_cfg_t* dev_cfg = embedd_i2c_get_dev_config( dev );
  if( dev_cfg == NULL )
  {
      return EMBEDD_RESULT_ERR;
  }

  //Writing data to the bus
  HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(&hi2c1, (dev_cfg->addr << 1), (uint8_t*)data_ptr, data_size, 100);
  if( status != HAL_OK)
  {
      return EMBEDD_RESULT_ERR;
  }

  return EMBEDD_RESULT_OK;
}

EMBEDD_RESULT ds3231_bus_read(const struct embedd_device_t* dev, uint8_t* data_ptr, uint32_t data_size)
{
  if( ( dev == NULL ) || ( data_ptr == NULL ) )
  {
      return EMBEDD_RESULT_ERR;
  }

  //Extracting I2C configurations from the device object
  embedd_i2c_dev_cfg_t* dev_cfg = embedd_i2c_get_dev_config( dev );
  if( dev_cfg == NULL ){
      return EMBEDD_RESULT_ERR;
  }

  //Reading data from the bus
  HAL_StatusTypeDef status = HAL_I2C_Master_Receive(&hi2c1, (dev_cfg->addr << 1), data_ptr, data_size, 100);
  if( status != HAL_OK)
  {
      return EMBEDD_RESULT_ERR;
  }

  return EMBEDD_RESULT_OK;
}

void embedd_hal_sleep( uint32_t mseconds )
{
    HAL_Delay(mseconds);
}

void debug(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    uint16_t debug_msg_size = vsnprintf((char *)debug_buf, sizeof debug_buf, format, args);
    va_end(args);

    HAL_UART_Transmit(&huart2, debug_buf, debug_msg_size, 100);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
