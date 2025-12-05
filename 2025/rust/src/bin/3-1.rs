use std::fs;
fn main() {
    let input = fs::read_to_string("../inputs/3.txt").expect("Couldn't read the file");
    let mut result: u64 = 0;
    input.trim().lines().for_each(|value| {
        let mut tenner = '0' as u8;
        let mut oner = '0' as u8;
        for a in 0..value.len() {
            let char = value.chars().nth(a).unwrap() as u8;
            if char > tenner {
                if a + 1 < value.len() {
                    tenner = char;
                    oner = value.chars().nth(a + 1).unwrap() as u8;
                    continue;
                }
            }
            if char > oner {
                oner = char;
            }
        }
        // wanted to subtract '0' didn't work for some reason
        result += ((tenner as char).to_digit(10).unwrap() * 10
            + (oner as char).to_digit(10).unwrap()) as u64;
    });
    println!("{}", result);
}
