use std::fs;

fn extract_number(string: &str) -> i32 {
    let numbers: String = string.chars().skip(1).collect();
    numbers.parse::<i32>().unwrap()
}

enum Direction {
    Left,
    Right,
}

fn main() {
    let input = fs::read_to_string("../inputs/1.txt").expect("Couldn't read the file");
    let mut result: i32 = 0;
    let mut number: i32 = 50;
    for row in input.lines() {
        let direction = match row.chars().next().unwrap() {
            'R' => Direction::Right,
            'L' => Direction::Left,
            c => panic!("Invalid char {}", c),
        };
        let repetition = extract_number(row);

        for _ in 0..repetition {
            if matches!(direction, Direction::Right) {
                number = (number + 1) % 100;
            } else {
                number = (number + 99) % 100;
            }

            if number == 0 {
                result += 1;
            }
        }
    }

    println!("{}", result);
}
