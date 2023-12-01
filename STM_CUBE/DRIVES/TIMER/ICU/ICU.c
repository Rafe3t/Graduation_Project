/*=================================================================================*/
/*  File        : ICU.c                                                  */
/*  Description : This file includes PORT Driver implementations for STM32F407VGT6 */
/*  Author      : Mohamed Maged Mohamed. Embedded SW Engineer                      */
/*  Date        : 25/11/2023                                                       */
/*  Linkedin    : www.linkedin.com/in/mohamed-elsayed-5636ab289                    */
/*  mail        : mhamedmaged169@gmil.com                                          */
/*=================================================================================*/
#include"ICU.h"

/** @defgroup TIM_Exported_Functions_Group4 TIM Input Capture functions
  *  @brief    TIM Input Capture functions
  *
@verbatim
  ==============================================================================
              ##### TIM Input Capture functions #####
  ==============================================================================
 [..]
   This section provides functions allowing to:
   (+) Initialize and configure the TIM Input Capture.
   (+) De-initialize the TIM Input Capture.
   (+) Start the TIM Input Capture.
   (+) Stop the TIM Input Capture.
   (+) Start the TIM Input Capture and enable interrupt.
   (+) Stop the TIM Input Capture and disable interrupt.
   (+) Start the TIM Input Capture and enable DMA transfer.
   (+) Stop the TIM Input Capture and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the TIM Input Capture Time base according to the specified
  *         parameters in the TIM_HandleTypeDef and initializes the associated handle.
  * @note   Switching from Center Aligned counter mode to Edge counter mode (or reverse)
  *         requires a timer reset to avoid unexpected direction
  *         due to DIR bit readonly in center aligned mode.
  *         Ex: call @ref HAL_TIM_IC_DeInit() before HAL_TIM_IC_Init()
  * @param  htim TIM Input Capture handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_IC_Init(TIM_HandleTypeDef *htim)
{
  /* Check the TIM handle allocation */
  if (htim == NULL_PTR)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_TIM_INSTANCE(htim->Instance));
  assert_param(IS_TIM_COUNTER_MODE(htim->Init.CounterMode));
  assert_param(IS_TIM_CLOCKDIVISION_DIV(htim->Init.ClockDivision));
  assert_param(IS_TIM_AUTORELOAD_PRELOAD(htim->Init.AutoReloadPreload));

  if (htim->State == HAL_TIM_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    htim->Lock = HAL_UNLOCKED;

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
    /* Reset interrupt callbacks to legacy weak callbacks */
    TIM_ResetCallback(htim);

    if (htim->IC_MspInitCallback == NULL_PTR)
    {
      htim->IC_MspInitCallback = HAL_TIM_IC_MspInit;
    }
    /* Init the low level hardware : GPIO, CLOCK, NVIC */
    htim->IC_MspInitCallback(htim);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC and DMA */
    HAL_TIM_IC_MspInit(htim);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
  }

  /* Set the TIM state */
  htim->State = HAL_TIM_STATE_BUSY;

  /* Init the base time for the input capture */
  TIM_Base_SetConfig(htim->Instance, &htim->Init);

  /* Initialize the DMA burst operation state */
  htim->DMABurstState = HAL_DMA_BURST_STATE_READY;

  /* Initialize the TIM channels state */
  TIM_CHANNEL_STATE_SET_ALL(htim, HAL_TIM_CHANNEL_STATE_READY);
  TIM_CHANNEL_N_STATE_SET_ALL(htim, HAL_TIM_CHANNEL_STATE_READY);

  /* Initialize the TIM state*/
  htim->State = HAL_TIM_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  DeInitializes the TIM peripheral
  * @param  htim TIM Input Capture handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_IC_DeInit(TIM_HandleTypeDef *htim)
{
  /* Check the parameters */
  assert_param(IS_TIM_INSTANCE(htim->Instance));

  htim->State = HAL_TIM_STATE_BUSY;

  /* Disable the TIM Peripheral Clock */
  __HAL_TIM_DISABLE(htim);

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
  if (htim->IC_MspDeInitCallback == NULL_PTR)
  {
    htim->IC_MspDeInitCallback = HAL_TIM_IC_MspDeInit;
  }
  /* DeInit the low level hardware */
  htim->IC_MspDeInitCallback(htim);
#else
  /* DeInit the low level hardware: GPIO, CLOCK, NVIC and DMA */
  HAL_TIM_IC_MspDeInit(htim);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

  /* Change the DMA burst operation state */
  htim->DMABurstState = HAL_DMA_BURST_STATE_RESET;

  /* Change the TIM channels state */
  TIM_CHANNEL_STATE_SET_ALL(htim, HAL_TIM_CHANNEL_STATE_RESET);
  TIM_CHANNEL_N_STATE_SET_ALL(htim, HAL_TIM_CHANNEL_STATE_RESET);

  /* Change TIM state */
  htim->State = HAL_TIM_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(htim);

  return HAL_OK;
}

/**
  * @brief  Initializes the TIM Input Capture MSP.
  * @param  htim TIM Input Capture handle
  * @retval None
  */
__weak void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_IC_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes TIM Input Capture MSP.
  * @param  htim TIM handle
  * @retval None
  */
__weak void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_IC_MspDeInit could be implemented in the user file
   */
}

/**
  * @brief  Starts the TIM Input Capture measurement.
  * @param  htim TIM Input Capture handle
  * @param  Channel TIM Channels to be enabled
  *          This parameter can be one of the following values:
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_IC_Start(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  uint32_t tmpsmcr;
  HAL_TIM_ChannelStateTypeDef channel_state = TIM_CHANNEL_STATE_GET(htim, Channel);
  HAL_TIM_ChannelStateTypeDef complementary_channel_state = TIM_CHANNEL_N_STATE_GET(htim, Channel);

  /* Check the parameters */
  assert_param(IS_TIM_CCX_INSTANCE(htim->Instance, Channel));

  /* Check the TIM channel state */
  if ((channel_state != HAL_TIM_CHANNEL_STATE_READY)
      || (complementary_channel_state != HAL_TIM_CHANNEL_STATE_READY))
  {
    return HAL_ERROR;
  }

  /* Set the TIM channel state */
  TIM_CHANNEL_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_BUSY);
  TIM_CHANNEL_N_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_BUSY);

  /* Enable the Input Capture channel */
  TIM_CCxChannelCmd(htim->Instance, Channel, TIM_CCx_ENABLE);

  /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
  if (IS_TIM_SLAVE_INSTANCE(htim->Instance))
  {
    tmpsmcr = htim->Instance->SMCR & TIM_SMCR_SMS;
    if (!IS_TIM_SLAVEMODE_TRIGGER_ENABLED(tmpsmcr))
    {
      __HAL_TIM_ENABLE(htim);
    }
  }
  else
  {
    __HAL_TIM_ENABLE(htim);
  }

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the TIM Input Capture measurement.
  * @param  htim TIM Input Capture handle
  * @param  Channel TIM Channels to be disabled
  *          This parameter can be one of the following values:
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_IC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_TIM_CCX_INSTANCE(htim->Instance, Channel));

  /* Disable the Input Capture channel */
  TIM_CCxChannelCmd(htim->Instance, Channel, TIM_CCx_DISABLE);

  /* Disable the Peripheral */
  __HAL_TIM_DISABLE(htim);

  /* Set the TIM channel state */
  TIM_CHANNEL_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_READY);
  TIM_CHANNEL_N_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_READY);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Starts the TIM Input Capture measurement in interrupt mode.
  * @param  htim TIM Input Capture handle
  * @param  Channel TIM Channels to be enabled
  *          This parameter can be one of the following values:
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_IC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tmpsmcr;

  HAL_TIM_ChannelStateTypeDef channel_state = TIM_CHANNEL_STATE_GET(htim, Channel);
  HAL_TIM_ChannelStateTypeDef complementary_channel_state = TIM_CHANNEL_N_STATE_GET(htim, Channel);

  /* Check the parameters */
  assert_param(IS_TIM_CCX_INSTANCE(htim->Instance, Channel));

  /* Check the TIM channel state */
  if ((channel_state != HAL_TIM_CHANNEL_STATE_READY)
      || (complementary_channel_state != HAL_TIM_CHANNEL_STATE_READY))
  {
    return HAL_ERROR;
  }

  /* Set the TIM channel state */
  TIM_CHANNEL_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_BUSY);
  TIM_CHANNEL_N_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_BUSY);

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {
      /* Enable the TIM Capture/Compare 1 interrupt */
      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC1);
      break;
    }

    case TIM_CHANNEL_2:
    {
      /* Enable the TIM Capture/Compare 2 interrupt */
      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC2);
      break;
    }

    case TIM_CHANNEL_3:
    {
      /* Enable the TIM Capture/Compare 3 interrupt */
      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC3);
      break;
    }

    case TIM_CHANNEL_4:
    {
      /* Enable the TIM Capture/Compare 4 interrupt */
      __HAL_TIM_ENABLE_IT(htim, TIM_IT_CC4);
      break;
    }

    default:
      status = HAL_ERROR;
      break;
  }

  if (status == HAL_OK)
  {
    /* Enable the Input Capture channel */
    TIM_CCxChannelCmd(htim->Instance, Channel, TIM_CCx_ENABLE);

    /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
    if (IS_TIM_SLAVE_INSTANCE(htim->Instance))
    {
      tmpsmcr = htim->Instance->SMCR & TIM_SMCR_SMS;
      if (!IS_TIM_SLAVEMODE_TRIGGER_ENABLED(tmpsmcr))
      {
        __HAL_TIM_ENABLE(htim);
      }
    }
    else
    {
      __HAL_TIM_ENABLE(htim);
    }
  }

  /* Return function status */
  return status;
}

/**
  * @brief  Stops the TIM Input Capture measurement in interrupt mode.
  * @param  htim TIM Input Capture handle
  * @param  Channel TIM Channels to be disabled
  *          This parameter can be one of the following values:
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_IC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_TIM_CCX_INSTANCE(htim->Instance, Channel));

  switch (Channel)
  {
    case TIM_CHANNEL_1:
    {
      /* Disable the TIM Capture/Compare 1 interrupt */
      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
      break;
    }

    case TIM_CHANNEL_2:
    {
      /* Disable the TIM Capture/Compare 2 interrupt */
      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC2);
      break;
    }

    case TIM_CHANNEL_3:
    {
      /* Disable the TIM Capture/Compare 3 interrupt */
      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC3);
      break;
    }

    case TIM_CHANNEL_4:
    {
      /* Disable the TIM Capture/Compare 4 interrupt */
      __HAL_TIM_DISABLE_IT(htim, TIM_IT_CC4);
      break;
    }

    default:
      status = HAL_ERROR;
      break;
  }

  if (status == HAL_OK)
  {
    /* Disable the Input Capture channel */
    TIM_CCxChannelCmd(htim->Instance, Channel, TIM_CCx_DISABLE);

    /* Disable the Peripheral */
    __HAL_TIM_DISABLE(htim);

    /* Set the TIM channel state */
    TIM_CHANNEL_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_READY);
    TIM_CHANNEL_N_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_READY);
  }

  /* Return function status */
  return status;
}

