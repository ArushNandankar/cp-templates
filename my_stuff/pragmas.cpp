// Pragmas to be used as a last resort
// to fix TLEs

#pragma GCC optimize("Ofast")                    // Faster than O3 (disables strict IEEE compliance)
#pragma GCC optimize("unroll-loops")             // Unroll loops to reduce overhead
#pragma GCC optimize("inline")                   // Optimize function inlining
#pragma GCC optimize("omit-frame-pointer")       // Omit frame pointer for faster function calls

#pragma GCC target("avx2")                       // Use AVX2 for more vectorization

#pragma GCC optimize("fast-math")                // Less accurate but faster math operations
#pragma GCC optimize("unsafe-math-optimizations") // Allow unsafe floating-point optimizations

#pragma GCC optimize("no-stack-protector")       // Disable stack protection (faster but less safe)
#pragma GCC optimize("rename-registers")         // Use register renaming for better performance

#pragma GCC optimize("tree-vectorize")           // Enable auto-vectorization
#pragma GCC optimize("unswitch-loops")           // Optimize loops by unswitching them
#pragma GCC optimize("inline-functions-called-once") // Inline functions called only once
#pragma GCC optimize("inline-small-functions")   // Inline small functions for speed
#pragma GCC optimize("crossjumping")             // Merge similar code blocks

#pragma GCC optimize("dce")                      // Dead code elimination (removes unused code)
#pragma GCC optimize("dse")                      // Dead store elimination (removes unnecessary stores)
