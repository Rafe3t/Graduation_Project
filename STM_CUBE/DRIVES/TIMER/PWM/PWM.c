/*=================================================================================*/
/*  File        : PWM.c                                                */
/*  Description : This file includes PORT Driver implementations for STM32F407VGT6 */
/*  Author      : Mohamed Maged Mohamed. Embedded SW Engineer                      */
/*  Date        : 25/11/2023                                                       */
/*  Linkedin    : www.linkedin.com/in/mohamed-elsayed-5636ab289                    */
/*  mail        : mhamedmaged169@gmil.com                                          */
/*=================================================================================*/
#include"PWM.h"

/*==============================================================================
                          ##### TIM PWM functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the TIM PWM.
    (+) De-initialize the TIM PWM.
    (+) Start the TIM PWM.
    (+) Stop the TIM PWM.
    (+) Start the TIM PWM and enable interrupt.
    (+) Stop the TIM PWM and disable interrupt.
    (+) Start the TIM PWM and enable DMA transfer.
    (+) Stop the TIM PWM and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the TIM PWM Time Base according to the specified
  *         parameters in the TIM_HandleTypeDef and initializes the associated handle.
  * @note   Switching from Center Aligned counter mode to Edge counter mode (or reverse)
  *         requires a timer reset to avoid unexpected direction
  *         due to DIR bit readonly in center aligned mode.
  *         Ex: call @ref HAL_TIM_PWM_DeInit() before HAL_TIM_PWM_Init()
  * @param  htim TIM PWM handle
  * @retval HAL status
  */

HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim)
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

    if (htim->PWM_MspInitCallback == NULL_PTR)
    {
      htim->PWM_MspInitCallback = HAL_TIM_PWM_MspInit;
    }
    /* Init the low level hardware : GPIO, CLOCK, NVIC */
    htim->PWM_MspInitCallback(htim);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC and DMA */
    HAL_TIM_PWM_MspInit(htim);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
  }

  /* Set the TIM state */
  htim->State = HAL_TIM_STATE_BUSY;

  /* Init the base time for the PWM */
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
  * @param  htim TIM PWM handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim)
{
  /* Check the parameters */
  assert_param(IS_TIM_INSTANCE(htim->Instance));

  htim->State = HAL_TIM_STATE_BUSY;

  /* Disable the TIM Peripheral Clock */
  __HAL_TIM_DISABLE(htim);

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
  if (htim->PWM_MspDeInitCallback == NULL_PTR)
  {
    htim->PWM_MspDeInitCallback = HAL_TIM_PWM_MspDeInit;
  }
  /* DeInit the low level hardware */
  htim->PWM_MspDeInitCallback(htim);
#else
  /* DeInit the low level hardware: GPIO, CLOCK, NVIC and DMA */
  HAL_TIM_PWM_MspDeInit(htim);
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
  * @brief  Initializes the TIM PWM MSP.
  * @param  htim TIM PWM handle
  * @retval None
  */
__weak void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_PWM_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes TIM PWM MSP.
  * @param  htim TIM PWM handle
  * @retval None
  */
__weak void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_PWM_MspDeInit could be implemented in the user file
   */
}

/**
  * @brief  Starts the PWM signal generation.
  * @param  htim TIM handle
  * @param  Channel TIM Channels to be enabled
  *          This parameter can be one of the following values:
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  uint32_t tmpsmcr;

  /* Check the parameters */
  assert_param(IS_TIM_CCX_INSTANCE(htim->Instance, Channel));

  /* Check the TIM channel state */
  if (TIM_CHANNEL_STATE_GET(htim, Channel) != HAL_TIM_CHANNEL_STATE_READY)
  {
    return HAL_ERROR;
  }

  /* Set the TIM channel state */
  TIM_CHANNEL_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_BUSY);

  /* Enable the Capture compare channel */
  TIM_CCxChannelCmd(htim->Instance, Channel, TIM_CCx_ENABLE);

  if (IS_TIM_BREAK_INSTANCE(htim->Instance) != RESET)
  {
    /* Enable the main output */
    __HAL_TIM_MOE_ENABLE(htim);
  }

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
  * @brief  Stops the PWM signal generation.
  * @param  htim TIM PWM handle
  * @param  Channel TIM Channels to be disabled
  *          This parameter can be one of the following values:
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_PWM_Stop(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  /* Check the parameters */
  assert_param(IS_TIM_CCX_INSTANCE(htim->Instance, Channel));

  /* Disable the Capture compare channel */
  TIM_CCxChannelCmd(htim->Instance, Channel, TIM_CCx_DISABLE);

  if (IS_TIM_BREAK_INSTANCE(htim->Instance) != RESET)
  {
    /* Disable the Main Output */
    __HAL_TIM_MOE_DISABLE(htim);
  }

  /* Disable the Peripheral */
  __HAL_TIM_DISABLE(htim);

  /* Set the TIM channel state */
  TIM_CHANNEL_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_READY);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Starts the PWM signal generation in interrupt mode.
  * @param  htim TIM PWM handle
  * @param  Channel TIM Channel to be enabled
  *          This parameter can be one of the following values:
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tmpsmcr;

  /* Check the parameters */
  assert_param(IS_TIM_CCX_INSTANCE(htim->Instance, Channel));

  /* Check the TIM channel state */
  if (TIM_CHANNEL_STATE_GET(htim, Channel) != HAL_TIM_CHANNEL_STATE_READY)
  {
    return HAL_ERROR;
  }

  /* Set the TIM channel state */
  TIM_CHANNEL_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_BUSY);

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
    /* Enable the Capture compare channel */
    TIM_CCxChannelCmd(htim->Instance, Channel, TIM_CCx_ENABLE);

    if (IS_TIM_BREAK_INSTANCE(htim->Instance) != RESET)
    {
      /* Enable the main output */
      __HAL_TIM_MOE_ENABLE(htim);
    }

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
  * @brief  Stops the PWM signal generation in interrupt mode.
  * @param  htim TIM PWM handle
  * @param  Channel TIM Channels to be disabled
  *          This parameter can be one of the following values:
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel)
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
    /* Disable the Capture compare channel */
    TIM_CCxChannelCmd(htim->Instance, Channel, TIM_CCx_DISABLE);

    if (IS_TIM_BREAK_INSTANCE(htim->Instance) != RESET)
    {
      /* Disable the Main Output */
      __HAL_TIM_MOE_DISABLE(htim);
    }

    /* Disable the Peripheral */
    __HAL_TIM_DISABLE(htim);

    /* Set the TIM channel state */
    TIM_CHANNEL_STATE_SET(htim, Channel, HAL_TIM_CHANNEL_STATE_READY);
  }

  /* Return function status */
  return status;
}
