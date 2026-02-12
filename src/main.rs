#![allow(unused)]

use core::marker::PhantomData;

#[derive(Debug, Copy, Clone)]
struct Idle;
#[derive(Debug, Copy, Clone)]
struct Armed;
#[derive(Debug, Copy, Clone)]
struct Launched;

#[derive(Debug, Copy, Clone)]
struct Rocket<State> {
    id: i32,
    _marker: PhantomData<State>,
}

impl Rocket<Idle> {
    pub fn new(id: i32) -> Self {
        let _rocket = Self {
            id,
            _marker: PhantomData,
        };
        println!("[rocket::new] -> {:?}", _rocket);
        return _rocket;
    }
    pub fn arm(self) -> Rocket<Armed> {
        let _rocket = Rocket {
            id: self.id,
            _marker: PhantomData,
        };
        println!("[rocket::arm] -> {:?}", _rocket);
        return _rocket;
    }
}

impl Rocket<Armed> {
    pub fn launch(self) -> Rocket<Launched> {
        let _rocket = Rocket {
            id: self.id,
            _marker: PhantomData,
        };
        println!("[rocket::launch] -> {:?}", _rocket);
        return _rocket;
    }
}

impl Rocket<Launched> {
    pub fn reset(self) -> Rocket<Idle> {
        let _rocket = Rocket {
            id: self.id,
            _marker: PhantomData,
        };
        println!("[rocket::reset] -> {:?}", _rocket);
        return _rocket;
    }
}

fn main() {
    let rocket = Rocket::new(111);
    rocket.arm().launch().reset();
}
