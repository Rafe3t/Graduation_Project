#ifndef MEMORY_MAPPING_DIO_H_
#define MEMORY_MAPPING_DIO_H_



#define GPIOA_BASE_ADDRESS                0x40020000                            
#define GPIOB_BASE_ADDRESS                0x40020400                            
#define GPIOC_BASE_ADDRESS                0x40020800   
#define GPIOD_BASE_ADDRESS                0x40020C00 
#define GPIOE_BASE_ADDRESS                0x40021000 
#define GPIOF_BASE_ADDRESS                0x40021400  
#define GPIOG_BASE_ADDRESS                0x40021800  
#define GPIOH_BASE_ADDRESS                0x40021C00           
#define GPIOI_BASE_ADDRESS                0x40022000 
#define GPIOJ_BASE_ADDRESS                0x40022400
#define GPIOK_BASE_ADDRESS                0x40022800

typedef unsigned long int uint32;	                      

#define GPIOA_MODER             *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x00)) // GPIO port mode register                                  
#define GPIOA_OTYPER            *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x04)) // GPIO port output type register
#define GPIOA_OSPEEDR           *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x08)) // GPIO port output speed register
#define GPIOA_PUPDR             *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x0C)) // GPIO port pull-up/pull-down register
#define GPIOA_IDR               *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x10)) // GPIO port input data register
#define GPIOA_ODR               *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x14)) // GPIO port output data register
#define GPIOA_BSRR              *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x18)) // GPIO port bit set/reset register
#define GPIOA_LCKR              *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x1C)) // GPIO port configuration lock register ,  not important
#define GPIOA_AFRL              *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x20)) // GPIO alternate function low register
#define GPIOA_AFRH              *((volatile uint32*)(GPIOA_BASE_ADDRESS+0x24)) // GPIO alternate function high register

#define GPIOB_MODER             *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOB_OTYPER            *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOB_OSPEEDR           *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOB_PUPDR             *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOB_IDR               *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOB_ODR               *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOB_BSRR              *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOB_LCKR              *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOB_AFRL              *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOB_AFRH              *((volatile uint32*)(GPIOB_BASE_ADDRESS+0x24))// GPIO alternate function high register

#define GPIOC_MODER             *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOC_OTYPER            *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOC_OSPEEDR           *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOC_PUPDR             *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOC_IDR               *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOC_ODR               *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOC_BSRR              *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOC_LCKR              *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOC_AFRL              *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOC_AFRH              *((volatile uint32*)(GPIOC_BASE_ADDRESS+0x24))// GPIO alternate function high register

#define GPIOD_MODER             *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOD_OTYPER            *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOD_OSPEEDR           *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOD_PUPDR             *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOD_IDR               *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOD_ODR               *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOD_BSRR              *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOD_LCKR              *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOD_AFRL              *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOD_AFRH              *((volatile uint32*)(GPIOD_BASE_ADDRESS+0x24))// GPIO alternate function high register

#define GPIOE_MODER             *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOE_OTYPER            *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOE_OSPEEDR           *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOE_PUPDR             *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOE_IDR               *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOE_ODR               *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOE_BSRR              *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOE_LCKR              *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOE_AFRL              *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOE_AFRH              *((volatile uint32*)(GPIOE_BASE_ADDRESS+0x24))// GPIO alternate function high register

#define GPIOF_MODER             *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOF_OTYPER            *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOF_OSPEEDR           *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOF_PUPDR             *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOF_IDR               *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOF_ODR               *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOF_BSRR              *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOF_LCKR              *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOF_AFRL              *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOF_AFRH              *((volatile uint32*)(GPIOF_BASE_ADDRESS+0x24))// GPIO alternate function high register

#define GPIOG_MODER             *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOG_OTYPER            *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOG_OSPEEDR           *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOG_PUPDR             *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOG_IDR               *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOG_ODR               *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOG_BSRR              *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOG_LCKR              *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOG_AFRL              *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOG_AFRH              *((volatile uint32*)(GPIOG_BASE_ADDRESS+0x24))// GPIO alternate function high register

#define GPIOH_MODER             *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOH_OTYPER            *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOH_OSPEEDR           *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOH_PUPDR             *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOH_IDR               *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOH_ODR               *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOH_BSRR              *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOH_LCKR              *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOH_AFRL              *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOH_AFRH              *((volatile uint32*)(GPIOH_BASE_ADDRESS+0x24))// GPIO alternate function high register

#define GPIOI_MODER             *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOI_OTYPER            *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOI_OSPEEDR           *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOI_PUPDR             *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOI_IDR               *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOI_ODR               *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOI_BSRR              *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOI_LCKR              *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOI_AFRL              *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOI_AFRH              *((volatile uint32*)(GPIOI_BASE_ADDRESS+0x24))// GPIO alternate function high register

#define GPIOJ_MODER             *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOJ_OTYPER            *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOJ_OSPEEDR           *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOJ_PUPDR             *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOJ_IDR               *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOJ_ODR               *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOJ_BSRR              *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOJ_LCKR              *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOJ_AFRL              *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOJ_AFRH              *((volatile uint32*)(GPIOJ_BASE_ADDRESS+0x24))// GPIO alternate function high register

#define GPIOK_MODER             *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x00))// GPIO port mode register                                
#define GPIOK_OTYPER            *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x04))// GPIO port output type register
#define GPIOK_OSPEEDR           *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x08))// GPIO port output speed register
#define GPIOK_PUPDR             *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x0C))// GPIO port pull-up/pull-down register
#define GPIOK_IDR               *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x10))// GPIO port input data register
#define GPIOK_ODR               *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x14))// GPIO port output data register
#define GPIOK_BSRR              *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x18))// GPIO port bit set/reset register
#define GPIOK_LCKR              *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x1C))// GPIO port configuration lock register ,  not important
#define GPIOK_AFRL              *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x20))// GPIO alternate function low register
#define GPIOK_AFRH              *((volatile uint32*)(GPIOK_BASE_ADDRESS+0x24))// GPIO alternate function high register

/*typedef struct
{
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}GPIO_MemMap_t;

#define GPIOA_REG     ((volatile GPIO_MemMap_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB_REG     ((volatile GPIO_MemMap_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC_REG     ((volatile GPIO_MemMap_t*)(GPIOC_BASE_ADDRESS))
#define GPIOD_REG     ((volatile GPIO_MemMap_t*)(GPIOD_BASE_ADDRESS))
#define GPIOE_REG     ((volatile GPIO_MemMap_t*)(GPIOE_BASE_ADDRESS))
#define GPIOF_REG     ((volatile GPIO_MemMap_t*)(GPIOF_BASE_ADDRESS))
#define GPIOG_REG     ((volatile GPIO_MemMap_t*)(GPIOG_BASE_ADDRESS))
#define GPIOH_REG     ((volatile GPIO_MemMap_t*)(GPIOH_BASE_ADDRESS))
#define GPIOI_REG     ((volatile GPIO_MemMap_t*)(GPIOI_BASE_ADDRESS))
#define GPIOJ_REG     ((volatile GPIO_MemMap_t*)(GPIOJ_BASE_ADDRESS))
#define GPIOK_REG     ((volatile GPIO_MemMap_t*)(GPIOK_BASE_ADDRESS))*/


#endif 