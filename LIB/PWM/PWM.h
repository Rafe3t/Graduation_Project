/*=================================================================================*/
/*  File        : PWM.h                                                           */
/*  Description : This file includes PORT Driver implementations for STM32F407VGT6 */
/*  Author      : Mohamed Maged Mohamed. Embedded SW Engineer                      */
/*  Date        : 25/11/2023                                                       */
/*  Linkedin    : www.linkedin.com/in/mohamed-elsayed-5636ab289                    */
/*  mail        : mhamedmaged169@gmil.com                                          */
/*=================================================================================*/
#include"common_macros.h"
#include"platform_types.h"
#include"TIMER_REG.h"
#ifndef PWM_H
#define PWM_H
/************************** DMA ***************************************************************/
typedef struct
{
 uint32_t CR;     /*!< DMA stream x configuration register      */
 uint32_t NDTR;   /*!< DMA stream x number of data register     */
 uint32_t PAR;    /*!< DMA stream x peripheral address register */
 uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
 uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
 uint32_t FCR;    /*!< DMA stream x FIFO control register       */
} DMA_Stream_TypeDef;

typedef struct
{
  uint32_t Channel;              /*!< Specifies the channel used for the specified stream. 
                                      This parameter can be a value of @ref DMA_Channel_selection                    */

  uint32_t Direction;            /*!< Specifies if the data will be transferred from memory to peripheral, 
                                      from memory to memory or from peripheral to memory.
                                      This parameter can be a value of @ref DMA_Data_transfer_direction              */

  uint32_t PeriphInc;            /*!< Specifies whether the Peripheral address register should be incremented or not.
                                      This parameter can be a value of @ref DMA_Peripheral_incremented_mode          */

  uint32_t MemInc;               /*!< Specifies whether the memory address register should be incremented or not.
                                      This parameter can be a value of @ref DMA_Memory_incremented_mode              */

  uint32_t PeriphDataAlignment;  /*!< Specifies the Peripheral data width.
                                      This parameter can be a value of @ref DMA_Peripheral_data_size                 */

  uint32_t MemDataAlignment;     /*!< Specifies the Memory data width.
                                      This parameter can be a value of @ref DMA_Memory_data_size                     */

  uint32_t Mode;                 /*!< Specifies the operation mode of the DMAy Streamx.
                                      This parameter can be a value of @ref DMA_mode
                                      @note The circular buffer mode cannot be used if the memory-to-memory
                                            data transfer is configured on the selected Stream                        */

  uint32_t Priority;             /*!< Specifies the software priority for the DMAy Streamx.
                                      This parameter can be a value of @ref DMA_Priority_level                       */

  uint32_t FIFOMode;             /*!< Specifies if the FIFO mode or Direct mode will be used for the specified stream.
                                      This parameter can be a value of @ref DMA_FIFO_direct_mode
                                      @note The Direct mode (FIFO mode disabled) cannot be used if the 
                                            memory-to-memory data transfer is configured on the selected stream       */

  uint32_t FIFOThreshold;        /*!< Specifies the FIFO threshold level.
                                      This parameter can be a value of @ref DMA_FIFO_threshold_level                  */

  uint32_t MemBurst;             /*!< Specifies the Burst transfer configuration for the memory transfers. 
                                      It specifies the amount of data to be transferred in a single non interruptible
                                      transaction.
                                      This parameter can be a value of @ref DMA_Memory_burst 
                                      @note The burst mode is possible only if the address Increment mode is enabled. */

  uint32_t PeriphBurst;          /*!< Specifies the Burst transfer configuration for the peripheral transfers. 
                                      It specifies the amount of data to be transferred in a single non interruptible 
                                      transaction. 
                                      This parameter can be a value of @ref DMA_Peripheral_burst
                                      @note The burst mode is possible only if the address Increment mode is enabled. */
}DMA_InitTypeDef;

typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,  /*!< DMA not yet initialized or disabled */
  HAL_DMA_STATE_READY             = 0x01U,  /*!< DMA initialized and ready for use   */
  HAL_DMA_STATE_BUSY              = 0x02U,  /*!< DMA process is ongoing              */
  HAL_DMA_STATE_TIMEOUT           = 0x03U,  /*!< DMA timeout state                   */
  HAL_DMA_STATE_ERROR             = 0x04U,  /*!< DMA error state                     */
  HAL_DMA_STATE_ABORT             = 0x05U,  /*!< DMA Abort state                     */
}HAL_DMA_StateTypeDef;


/*****************************************************************************************/
typedef struct
{
 uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
 uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
 uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
 uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
 uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
 uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
 uint32_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
 uint32_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
 uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
 uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
 uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
 uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
 uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
 uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
 uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
 uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
 uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
 uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
 uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
 uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
 uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
} TIM_TypeDef;
typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,    /*!< Peripheral not yet initialized or disabled  */
  HAL_TIM_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use    */
  HAL_TIM_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing              */
  HAL_TIM_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state                               */
  HAL_TIM_STATE_ERROR             = 0x04U     /*!< Reception process is ongoing                */
} HAL_TIM_StateTypeDef;
/******************/

typedef enum
{
  HAL_TIM_CHANNEL_STATE_RESET             = 0x00U,    /*!< TIM Channel initial state                         */
  HAL_TIM_CHANNEL_STATE_READY             = 0x01U,    /*!< TIM Channel ready for use                         */
  HAL_TIM_CHANNEL_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing on the TIM channel */
} HAL_TIM_ChannelStateTypeDef;

typedef enum
{
  HAL_TIM_CHANNEL_STATE_RESET             = 0x00U,    /*!< TIM Channel initial state                         */
  HAL_TIM_CHANNEL_STATE_READY             = 0x01U,    /*!< TIM Channel ready for use                         */
  HAL_TIM_CHANNEL_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing on the TIM channel */
} HAL_TIM_ChannelStateTypeDef;

typedef enum 
{
  HAL_UNLOCKED = 0x00U,
  HAL_LOCKED   = 0x01U  
} HAL_LockTypeDef;


typedef struct
{
  uint32_t Prescaler;         /*!< Specifies the prescaler value used to divide the TIM clock.
                                   This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */

  uint32_t CounterMode;       /*!< Specifies the counter mode.
                                   This parameter can be a value of @ref TIM_Counter_Mode */

  uint32_t Period;            /*!< Specifies the period value to be loaded into the active
                                   Auto-Reload Register at the next update event.
                                   This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF.  */

  uint32_t ClockDivision;     /*!< Specifies the clock division.
                                   This parameter can be a value of @ref TIM_ClockDivision */

  uint32_t RepetitionCounter;  /*!< Specifies the repetition counter value. Each time the RCR downcounter
                                    reaches zero, an update event is generated and counting restarts
                                    from the RCR value (N).
                                    This means in PWM mode that (N+1) corresponds to:
                                        - the number of PWM periods in edge-aligned mode
                                        - the number of half PWM period in center-aligned mode
                                     GP timers: this parameter must be a number between Min_Data = 0x00 and
                                     Max_Data = 0xFF.
                                     Advanced timers: this parameter must be a number between Min_Data = 0x0000 and
                                     Max_Data = 0xFFFF. */

  uint32_t AutoReloadPreload;  /*!< Specifies the auto-reload preload.
                                   This parameter can be a value of @ref TIM_AutoReloadPreload */
} TIM_Base_InitTypeDef;


typedef struct __DMA_HandleTypeDef
{
  DMA_Stream_TypeDef         *Instance;                                                        /*!< Register base address                  */

  DMA_InitTypeDef            Init;                                                             /*!< DMA communication parameters           */ 

  HAL_LockTypeDef            Lock;                                                             /*!< DMA locking object                     */  

 HAL_DMA_StateTypeDef  State;                                                            /*!< DMA transfer state                     */

  void                       *Parent;                                                          /*!< Parent object state                    */ 

  void                       (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);         /*!< DMA transfer complete callback         */

  void                       (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);     /*!< DMA Half transfer complete callback    */

  void                       (* XferM1CpltCallback)( struct __DMA_HandleTypeDef * hdma);       /*!< DMA transfer complete Memory1 callback */
  
  void                       (* XferM1HalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);   /*!< DMA transfer Half complete Memory1 callback */
  
  void                       (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);        /*!< DMA transfer error callback            */
  
  void                       (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);        /*!< DMA transfer Abort callback            */  

  uint32_t              ErrorCode;                                                        /*!< DMA Error code                          */
  
  uint32_t                   StreamBaseAddress;                                                /*!< DMA Stream Base Address                */

  uint32_t                   StreamIndex;                                                      /*!< DMA Stream Index                       */
 
}DMA_HandleTypeDef;


typedef enum
{
  HAL_TIM_ACTIVE_CHANNEL_1        = 0x01U,    /*!< The active channel is 1     */
  HAL_TIM_ACTIVE_CHANNEL_2        = 0x02U,    /*!< The active channel is 2     */
  HAL_TIM_ACTIVE_CHANNEL_3        = 0x04U,    /*!< The active channel is 3     */
  HAL_TIM_ACTIVE_CHANNEL_4        = 0x08U,    /*!< The active channel is 4     */
  HAL_TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< All active channels cleared */
} HAL_TIM_ActiveChannel;

typedef enum
{
  HAL_DMA_BURST_STATE_RESET             = 0x00U,    /*!< DMA Burst initial state */
  HAL_DMA_BURST_STATE_READY             = 0x01U,    /*!< DMA Burst ready for use */
  HAL_DMA_BURST_STATE_BUSY              = 0x02U,    /*!< Ongoing DMA Burst       */
} HAL_TIM_DMABurstStateTypeDef;


/****************************************************************************************/
typedef enum 
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;
/******************************************************************************************************/
typedef struct /* USE_HAL_TIM_REGISTER_CALLBACKS */
{
TIM_TypeDef                        *Instance;         /*!< Register base address                             */
TIM_Base_InitTypeDef               Init;              /*!< TIM Time Base required parameters                 */
HAL_TIM_ActiveChannel              Channel;           /*!< Active channel                                    */
DMA_HandleTypeDef                  *hdma[7];          /*!< DMA Handlers array
   This array is accessed by a @ref DMA_Handle_index */
 HAL_LockTypeDef               Lock;              /*!< Locking object                                    */
 HAL_TIM_StateTypeDef          State;             /*!< TIM operation state                               */
 HAL_TIM_ChannelStateTypeDef   ChannelState[4];   /*!< TIM channel operation state                       */
 HAL_TIM_ChannelStateTypeDef   ChannelNState[4];  /*!< TIM complementary channel operation state         */
 HAL_TIM_DMABurstStateTypeDef  DMABurstState;     /*!< DMA burst operation state  */
}TIM_HandleTypeDef;
/*******************************************************************************************************/


/**********************************FUNCTION***********************************************/
/********************************MOHAMED MAGED********************************************/
/*******************************SINGEL****************************************************/
/*****************************01156070710*************************************************/
/****************************LOOKING FOR DIVORCED WOMAN***********************************/

/* Timer PWM functions ********************************************************/
HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim);
/* Blocking mode: Polling */
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
/* Non-Blocking mode: Interrupt */
HAL_StatusTypeDef HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* Non-Blocking mode: DMA */
HAL_StatusTypeDef HAL_TIM_PWM_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIM_PWM_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);









#endif