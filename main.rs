#![allow(dead_code)]
mod slow;
mod miller_rabin;

fn main() {
    // Normal prime finding method
    // let x: i32 = slow::find_prime(2, 10000);
    let x: i128 = miller_rabin::find_prime( 100000);
    
    println!("{x}");
}
