/* FastEmbedded Microcontroller Library
 * Copyright (c) 2018-2028 Gene Kong
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
void __attribute__((noreturn)) assert_failed(const char *file, int line)
{
    while(1);
}

#if __CC_ARM
/*
 * refer: http://www.keil.com/support/man/docs/armlib/armlib_chr1358938924063.htm
 * A program can exit normally at the end of main() or it can exit prematurely
 * because of an error.
 * The behavior of the assert macro depends on a number of conditions:
 *  1. If the NDEBUG macro is defined (on the command line or as part of a source file),
 *      the assert macro has no effect.
 *  2. If the NDEBUG macro is not defined, the assert expression
 *      (the expression given to the assert macro) is evaluated. If the result
 *      is TRUE, that is != 0, the assert macro has no more effect.
 *  3. If the assert expression evaluates to FALSE, the assert macro calls the
 *      *. __aeabi_assert() function if any of the following are true:
 *      *. You are compiling with --strict.
 *      *. You are using -O0 or -O1.
 *      *. __OPT_SMALL_ASSERT is defined.
 *      *. __ASSERT_MSG is defined.
 *      *. _AEABI_PORTABILITY_LEVEL is defined and not 0.
 *  4. If the assert expression evaluates to FALSE and the conditions specified
 *      in point 3 do not apply, the assert macro calls abort(). Then:
 *      abort() calls __rt_raise().
 *      If __rt_raise() returns, abort() tries to finalize the library.
 * If you are creating an application that does not use the library, __aeabi_assert()
 *  works if you re-implement abort() and the stdio functions.
 * Another solution for retargeting is to re-implement the __aeabi_assert()
 * function itself. The function prototype is:
 *  `void __aeabi_assert(const char *expr, const char *file, int line);`
 *  where:
 *      expr points to the string representation of the expression that was not TRUE.
 *      file and line identify the source location of the assertion.
 *      The behavior for __aeabi_assert() supplied in the ARM C library is to print
 *       a message on stderr and call abort().
 */
void __attribute__((noreturn)) abort(void)
{
    while(1);
}

void __aeabi_assert(const char *expr, const char *file, int line)
{
    assert_failed(file, line);
}

#endif
