/*=========================================================================================*/
/*  File          : DIO.h                                                                  */
/*  Description   : This file includes DIO Driver By Autosar standaard for stm32f407vgt6   */
/*  Author  :1    : MohammedMagedMohamed. Embedded SW Engineer                             */
/*  Author  :2    : Sherif Mokhtar. Embedded SW Engineer                                   */
/*  Date          : 24/9/2023                                                              */
/*  Linkedin :1   :                                                                        */
/*  Git account:1 :                                                                        */
/*  mail     :1   :                                                                        */
/*  Linkedin :2   :                                                                        */
/*  Git account:2 :                                                                        */
/*  mail     :2   :                                                                        */
/*=========================================================================================*/


/*******************************************************************************************/
/********************************* Module Type Defention************************************/
/*******************************************************************************************/
typedef enum
{
	STD_LOW,STD_HIGH
}Dio_LevelType;
                           /*****************************/
	 /*If the μC owns ports of different port widths (e.g. 4, 8,16...Bit)
          Dio_PortLevelType inherits the size of the largest port.*/
typedef enum      
{                
	port_Width_4=4,port_Width_8=8,port_Width_16=16,port_Width_32=32
}Dio_PortLevelType;
 /*Note: i think it will fit with us if we put it 32 always but i entend to write portable drive */
                           /***************************/
typedef enum
{
	PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7,PIN_8,PIN_9,PIN_10,PIN_11,PIN_12
}Dio_ChannelType;					   
                         /*****************************/
typedef enum
{
	POTRA,POTRB,POTRC,POTRD,POTRE,POTRF,POTRG,POTRH,POTRI
}Dio_PortType;						 
typedef struct
{
	/*port level define number of bits that this port have*/
	Dio_PortLevelType Port_Level;
	/*PORT_ID that set which port you want*/
	Dio_PortType PORT_ID;
	/*Channel_IDthat set which pin you want*/
	Dio_ChannelType Channel_ID;
	/*to set the mode (input or output)*/
	Dio_LevelType Mode;	
}Dio_ConfigType;


/*******************************************************************************************/
typedef unsigned char         uint8; 
/*******************************************************************************
 *                              Module Type Defention                          *
 *******************************************************************************/

/*typedef uint8 Dio_ChannelType;*/


/*typedef uint8 Dio_PortType;*/


/*typedef uint8 Dio_LevelType;*/


/*typedef uint8 Dio_PortLevelType;*/

/* Structure for Dio_ChannelGroup */

typedef struct
{
  /* Mask which defines the positions of the channel group */
  uint8 mask;
  /* Position of the group from LSB */
  uint8 offset;
  /* This shall be the port ID which the Channel group is defined. */
  Dio_PortType PortIndex;
} Dio_ChannelGroupType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


/************************************************************************************************/
/* Function Name : Dio_ReadPort                                                                 */
/* Description :  Function for DIO read Channel                                                 */
/* Fun. Argument1:Dio_PortType { POTRA,POTRB,POTRC,POTRD,POTRE,POTRF,POTRG,POTRH,POTRI }        */                                  */
/* Fun. Return : Dio_PortLevelType  {4,8,16,32};                                                */
/************************************************************************************************/
Dio_PortLevelType Dio_ReadPort
(Dio_PortType PortId);
/************************************************************************************************/
/* Function Name : Dio_ReadChannelGroup                                                         */
/* Description :  Function for DIO read Channel group                                           */
/* Fun. Argument1: Pointer to Struct Dio_ChannelGroupType {&ChannelGroupId}                     */                           
/* Fun. Return : Dio_PortLevelType  {4,8,16,32}                                                 */
/************************************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup
( const Dio_ChannelGroupType* ChannelGroupIdPtr );


/************************************************************************************************/
/* Function Name : Dio_WritePort                                                                */
/* Description :  Function for DIO write Channel                                                */
/* Fun. Argument1:Dio_PortType {POTRA,POTRB,POTRC,POTRD,POTRE,POTRF,POTRG,POTRH,POTRI}          */                                                       
/* Fun. Argument2:Dio_PortLevelType  {4,8,16,32}                                                */            
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void Dio_WritePort
(Dio_PortType PortId, 
Dio_PortLevelType Level);


/********************************************************************************************************************/
/* Function Name : Dio_ReadChannel (Read_PIN)                                                                       */
/* Description :  Function for DIO read Port                                                                        */
/* Fun. Argument1:Dio_ChannelType{PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7,PIN_8,PIN_9,PIN_10,PIN_11,PIN_12}       */                          
/* Fun. Return : Dio_LevelType  {STD_LOW,STD_HIGH}                                                                  */
/********************************************************************************************************************/
Dio_LevelType Dio_ReadChannel
(Dio_ChannelType ChannelId);


/********************************************************************************************************************/
/* Function Name : Dio_WriteChannel (Write_PIN)                                                                     */
/* Description :  Function for DIO write Channel                                                                    */
/* Fun. Argument1:Dio_ChannelType{PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7,PIN_8,PIN_9,PIN_10,PIN_11,PIN_12}       */ 
/* Fun. Argument2:Dio_LevelType  {STD_LOW,STD_HIGH}                                                                 */                          
/* Fun. Return : void                                                                                               */
/********************************************************************************************************************/
void Dio_WriteChannel
(Dio_ChannelType ChannelId, 
Dio_LevelType Level);

/********************************************************************************************************************/
/* Function Name : Dio_WriteChannelGroup                                                                            */
/* Description :  Function for DIO write group of pin                                                               */
/* Fun. Argument1:Pointer to Struct Dio_ChannelGroupType {&ChannelGroupId}                                          */ 
/* Fun. Argument2:Dio_PortLevelType  {4,8,16,32}                                                                    */                          
/* Fun. Return : void                                                                                               */
/********************************************************************************************************************/
void Dio_WriteChannelGroup
( const Dio_ChannelGroupType* ChannelGroupIdPtr,  
Dio_PortLevelType Level ) ;

/********************************************************************************************************************/
/* Function Name : Dio_Init                                                                                         */
/* Description :  Function for DIO Initialization                                                                   */
/* Fun. Argument1:Pointer to Struct Dio_ConfigType {&Config}                                                        */                          
/* Fun. Return : void                                                                                               */
/********************************************************************************************************************/

void Dio_Init(const Dio_ConfigType * ConfigPtr);