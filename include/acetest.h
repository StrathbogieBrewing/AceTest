// MIT License

// Copyright (c) 2023 Strathbogie Brewing Company

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef ACETEST_H
#define ACETEST_H
    void acetest_callback(const char* name, int line); 
    #ifdef ACETEST_ENABLED
        #define ACETEST_DO_STRINGIFY(x) #x
        #define ACETEST_STRINGIFY(s) ACETEST_DO_STRINGIFY(s)
        #define ACETEST_RUN(function) do { \
            void acetest_##function##_unit_test(const char* name); \
            acetest_##function##_unit_test(ACETEST_STRINGIFY(function)); } while (0)
        #define ACETEST_FUNCTION(function) \
            void acetest_##function##_unit_test(const char* name)
        #define ACETEST_ASSERT(assertion) do { if (assertion) acetest_callback(name, __LINE__); else acetest_callback(name, -(__LINE__));  } while (0)
    #else   // ACETEST_ENABLED - DISABLE AND REMOVE FROM BUILD
        #define ACETEST_RUN(function)
        #define ACETEST_FUNCTION(function) static inline __attribute__((always_inline)) void acetest_##function##_unit_test(const char* name)  
        #define ACETEST_ASSERT(assertion)
    #endif  // ACETEST_ENABLED
#endif  // ACETEST_H