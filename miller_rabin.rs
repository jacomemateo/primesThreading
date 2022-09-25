use rand::Rng;

fn modulo(a: i128, mut b: i128, n: i128) -> i128 {
    let mut x:i128 = 1;
    let mut y:i128 = a;

    while b > 0 {
        if b%2 == 1 {
            x = (x*y) % n;
        }
        y = (y*y) % n;
        b /= 2;
    }
    return x % n;
}


fn single_test(n: i128, a: i128) -> bool {
    let mut exp: i128 = n - 1;
    
    while (exp & 1) != 0  {
        exp >>= 1;
    }

    if modulo(a, exp, n) == 1 {
        return true;
    }
    while exp < n -1 {
        if modulo(a, exp, n) == n -1 {
            return true;
        }
        exp <<= 1;
    }
    return false;
}

fn miller_rabin(n: i128, test_runs: i128) -> bool {
    let mut a = rand::thread_rng();
    for _ in 0..test_runs {
        let a: i128 = a.gen_range(0..=n-1)+2; 
        if !single_test(n, a) {
            return false;
        }
    }
    return true;
}

pub fn find_prime(max: i128) -> i128 {
    let mut count: i128 = 0;

    for i in 2..=max {
        let value: bool = miller_rabin(i, 100);
        if value {
            count+= 1;
        }
    }

    return count;
}