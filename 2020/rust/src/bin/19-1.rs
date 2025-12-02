use std::{collections::HashMap, fs};

#[derive(Debug)]
enum Rule {
    Char(char),
    Sequence(Vec<usize>),
    Or(Vec<Vec<usize>>),
}

fn main() {
    let input = fs::read_to_string("../inputs/19.txt").expect("Couldn't read the file");
    let (rules_raw, messages) = input.split_once("\n\n").unwrap();

    let mut rules: HashMap<usize, Rule> = HashMap::new();

    for line in rules_raw.lines() {
        let (id, rule_str) = line.split_once(": ").unwrap();
        let id: usize = id.parse().unwrap();

        if rule_str.contains('"') {
            let c = rule_str
                .chars()
                .filter(|c| c.is_alphabetic())
                .nth(0)
                .unwrap();
            rules.insert(id, Rule::Char(c));
        } else if rule_str.contains('|') {
            let parts = rule_str
                .split(" | ")
                .map(|part| {
                    part.split_whitespace()
                        .map(|s| s.parse().unwrap())
                        .collect()
                })
                .collect();
            rules.insert(id, Rule::Or(parts));
        } else {
            let sequence = rule_str
                .split_whitespace()
                .map(|s| s.parse().unwrap())
                .collect();
            rules.insert(id, Rule::Sequence(sequence));
        }
    }

    println!("{:?}", rules);
}
