# Phantom Type Exploration

This concept was initially formalized in the Haskell community (Daan Leijen and Erik Meijer - 1999)

Inspired by this TDD (Type-Driven-Development) in Rust, this repo aims to implement a similar type as `PhantomData<T>`.<br>
As the [official documentation shows](https://doc.rust-lang.org/std/marker/struct.PhantomData.html) this is zero-sized.

In C we have to be artisanal to achieve similarity.

## The Core Concept
We will use incomplete structs as our "ghosts". Since we never define the body of these structs, we can never instantiate them. We can only pass pointers to them. These pointers serve as our "type tags".

