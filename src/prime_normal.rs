pub fn find_prime(min: i32, max: i32) -> i32 {
    let mut count: i32;
    let mut num: i32;
    let mut c: i32 = 0;

    for i in min..=max {
        num = i;
        count = 0;
        for x in 1..=num {
            if num%x == 0 {
                count+=1;
            }
        }
        if count == 2 {
            c+=1;
        }
    }

    return c;
}