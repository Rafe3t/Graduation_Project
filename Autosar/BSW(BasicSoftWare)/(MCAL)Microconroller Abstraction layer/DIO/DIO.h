
typedef unsigned char         uint8; 
/*******************************************************************************
 *                              Module Type Defention                          *
 *******************************************************************************/

typedef uint8 Dio_ChannelType;


typedef uint8 Dio_PortType;


typedef uint8 Dio_LevelType;


typedef uint8 Dio_PortLevelType;

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

/* Function for DIO read Channel */
Dio_PortLevelType Dio_ReadPort
(Dio_PortType PortId);
/* Function for DIO read Channel group  */
Dio_PortLevelType Dio_ReadChannelGroup
( const Dio_ChannelGroupType* ChannelGroupIdPtr );

/* Function for DIO write Channel  */
void Dio_WritePort
(Dio_PortType PortId,
 Dio_PortLevelType Level);

/* Function for DIO read Port  */
Dio_LevelType Dio_ReadChannel
(Dio_ChannelType ChannelId);

/* Function for DIO write pin  */
void Dio_WriteChannel
(Dio_ChannelType ChannelId, 
Dio_LevelType Level);
/* Function for DIO write group of pin  */
void Dio_WriteChannelGroup
 ( const Dio_ChannelGroupType* ChannelGroupIdPtr,
 Dio_PortLevelType Level ) ;

/* Function for DIO Initialization */
void Dio_Init
(const Dio_ConfigType * ConfigPtr);