use std::fs;
fn main() {
    let input = fs::read_to_string("../inputs/3.txt").expect("Couldn't read the file");
    let mut result: u64 = 0;
    input.trim().lines().for_each(|value| {
        let mut numbers = ['0' as u8; 12];
        for a in 0..value.len() {
            let char = value.chars().nth(a).unwrap() as u8;
            for b in 0..12 {
                if char > numbers[b] {
                    if a + 12 - b < value.len() {
                        for c in b..12 {
                            numbers[c] = value.chars().nth(a + 12 - c).unwrap() as u8;
                        }
                    }
                }
            }
        }
        // wanted to subtract '0' didn't work for some reason
        let mut tmp: u64 = 0;
        for a in 0..numbers.len() {
            tmp *= 10;
            tmp += ((numbers[a]) as char).to_digit(10).unwrap() as u64;
        }
        result += tmp
    });
    println!("{}", result);
}
