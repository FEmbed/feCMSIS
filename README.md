# feCMSIS
# CMSIS Library Port For FastEmbedded
## 使用说明

## TODO 手动修改
**所有的调整请再自己项目中自动生成的目录中修改。**
1. 默认中断函数需要调用`fe_common_interrupt`。
    ```
    .section .text.Default_Handler,"ax",%progbits
    Default_Handler:
    Infinite_Loop:
    b fe_common_interrupt   ///< update to fe_common_interrupt
        .size Default_Handler, .-Default_Handler
   ```
2. 如果是armcc编译（keil），默认堆栈大小仍然需要在.S中调整。
   ```
   Stack_Size      EQU     4
   Heap_Size       EQU     8192   
   ```
3. 如果是gcc编译器，堆栈大小在linker脚本里修改。