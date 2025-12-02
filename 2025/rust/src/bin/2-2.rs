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
            let s = a.to_string();
            let lenght = s.len();
            for parts in 2..=lenght {
                if lenght % parts != 0 {
                    continue;
                }

                let chunk_size = lenght / parts;
                let pattern = &s[0..chunk_size];

                let reconstructed = pattern.repeat(lenght / chunk_size);
                if reconstructed == s {
                    result += a;
                    break;
                }
            }
        }
    });
    println!("{}", result);
}
