use std::fs;
fn main() {
    let input = fs::read_to_string("../inputs/2.txt").expect("Couldn't read the file");
    let mut result: i64 = 0;
    input.trim().split(",").for_each(|value| {
        println!("{}", value);
        let mut split = value.split("-");
        let first: i64 = split.next().unwrap().parse().unwrap();
        let second: i64 = split.next().unwrap().parse().unwrap();
        for a in first..=second {
            let lenght: i64 = a.to_string().len() as i64;
            if lenght % 2 != 0 {
                continue;
            }
            let divisor = 10_i64.pow((lenght / 2).try_into().unwrap());
            let first_half = a / divisor;
            let second_half = a % divisor;
            if first_half - second_half == 0 {
                println!(
                    "value: {} len: {} first: {} second: {}",
                    value, lenght, first_half, second_half
                );
                result += a
            }
        }
    });
    println!("{}", result);
}
