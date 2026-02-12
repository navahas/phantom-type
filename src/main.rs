#![allow(unused)]

use core::marker::PhantomData;

#[derive(Debug, Copy, Clone)]
struct Idle;
struct Armed;
struct Launched;

#[derive(Debug, Copy, Clone)]
struct Rocket<State> {
    id: i32,
    _marker: PhantomData<State>
}

impl Rocket<Idle> {
    pub fn new() -> Self {
        Self {
            id: 12345,
            _marker: PhantomData
        }
    }
    pub fn arm(self) -> Rocket<Armed> {
        Rocket {
            id: self.id,
            _marker: PhantomData
        }
    }
}

impl Rocket<Armed> {
    pub fn launch(self) -> Rocket<Launched> {
        Rocket {
            id: self.id,
            _marker: PhantomData
        }
    }
}

impl Rocket<Launched> {
    pub fn reset(self) -> Rocket<Idle> {
        Rocket {
            id: self.id,
            _marker: PhantomData
        }
    }
}

fn main() {
    let rocket = Rocket::new();
    rocket.arm().launch().reset();
}
