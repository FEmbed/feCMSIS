# feCMSIS
# CMSIS Library Port For FastEmbedded
## 使用说明

## TODO 手动修改
1. 默认中断函数需要调用`fe_common_interrupt`.
    ```
    .section .text.Default_Handler,"ax",%progbits
    Default_Handler:
    Infinite_Loop:
    b fe_common_interrupt   ///< update to fe_common_interrupt
        .size Default_Handler, .-Default_Handler
   ```
2. 默认堆栈大小仍然需要在.S中调整