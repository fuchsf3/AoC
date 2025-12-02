use regex::Regex;
use std::fs;

struct Vec2 {
    x: u64,
    y: u64,
}

impl Vec2 {
    pub fn new(x: u64, y: u64) -> Self {
        Self { x, y }
    }
}

fn main() {
    let input = fs::read_to_string("../inputs/13.txt").expect("Couldn't read the file");
    let re =
            Regex::new(r"X\+(?<ax>\d+), Y\+(?<ay>\d+)\n\D+\+(?<bx>\d+), Y\+(?<by>\d+)\n\D+X=(?<px>\d+), Y=(?<py>\d+)").unwrap();

    let mut result1 = 0;
    let mut result2 = 0;

    for block in input.split("\n\n") {
        let cap = re.captures(block).unwrap();
        let a_button = Vec2::new(cap["ax"].parse().unwrap(), cap["ay"].parse().unwrap());
        let b_button = Vec2::new(cap["bx"].parse().unwrap(), cap["by"].parse().unwrap());
        let prize = Vec2::new(cap["px"].parse().unwrap(), cap["py"].parse().unwrap());
        let mut min_cost_for_this_machine_1 = u64::MAX;
        let mut min_cost_for_this_machine_2 = u64::MAX;

        for a in 0..=100 {
            for b in 0..=100 {
                if a * a_button.x + b * b_button.x == prize.x
                    && a * a_button.y + b * b_button.y == prize.y
                {
                    let current_cost = a * 3 + b * 1;
                    min_cost_for_this_machine_1 = min_cost_for_this_machine_1.min(current_cost);
                }

                if a * a_button.x + b * b_button.x == (prize.x + 10000000000000)
                    && a * a_button.y + b * b_button.y == (prize.y + 10000000000000)
                {
                    let current_cost = a * 3 + b * 1;
                    min_cost_for_this_machine_2 = min_cost_for_this_machine_2.min(current_cost);
                }
            }
        }
        if min_cost_for_this_machine_1 != u64::MAX {
            result1 += min_cost_for_this_machine_1
        }
        if min_cost_for_this_machine_2 != u64::MAX {
            result2 += min_cost_for_this_machine_2
        }
    }
    println!("Part 1: {result1}");
    println!("Part 2: {result2}");
}
