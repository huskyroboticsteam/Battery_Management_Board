/*******************************************************************************
* File Name: INA226_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_INA226_SCBCLK_H)
#define CY_CLOCK_INA226_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void INA226_SCBCLK_StartEx(uint32 alignClkDiv);
#define INA226_SCBCLK_Start() \
    INA226_SCBCLK_StartEx(INA226_SCBCLK__PA_DIV_ID)

#else

void INA226_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void INA226_SCBCLK_Stop(void);

void INA226_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 INA226_SCBCLK_GetDividerRegister(void);
uint8  INA226_SCBCLK_GetFractionalDividerRegister(void);

#define INA226_SCBCLK_Enable()                         INA226_SCBCLK_Start()
#define INA226_SCBCLK_Disable()                        INA226_SCBCLK_Stop()
#define INA226_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    INA226_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define INA226_SCBCLK_SetDivider(clkDivider)           INA226_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define INA226_SCBCLK_SetDividerValue(clkDivider)      INA226_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define INA226_SCBCLK_DIV_ID     INA226_SCBCLK__DIV_ID

#define INA226_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define INA226_SCBCLK_CTRL_REG   (*(reg32 *)INA226_SCBCLK__CTRL_REGISTER)
#define INA226_SCBCLK_DIV_REG    (*(reg32 *)INA226_SCBCLK__DIV_REGISTER)

#define INA226_SCBCLK_CMD_DIV_SHIFT          (0u)
#define INA226_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define INA226_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define INA226_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define INA226_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << INA226_SCBCLK_CMD_DISABLE_SHIFT))
#define INA226_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << INA226_SCBCLK_CMD_ENABLE_SHIFT))

#define INA226_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define INA226_SCBCLK_DIV_FRAC_SHIFT (3u)
#define INA226_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define INA226_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define INA226_SCBCLK_DIV_REG        (*(reg32 *)INA226_SCBCLK__REGISTER)
#define INA226_SCBCLK_ENABLE_REG     INA226_SCBCLK_DIV_REG
#define INA226_SCBCLK_DIV_FRAC_MASK  INA226_SCBCLK__FRAC_MASK
#define INA226_SCBCLK_DIV_FRAC_SHIFT (16u)
#define INA226_SCBCLK_DIV_INT_MASK   INA226_SCBCLK__DIVIDER_MASK
#define INA226_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_INA226_SCBCLK_H) */

/* [] END OF FILE */