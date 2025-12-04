use std::fs;
fn main() {
    // cheating xD
    const LENGHT_X: usize = 141;
    const LENGHT_Y: usize = 141;

    let input = fs::read_to_string("../inputs/4.txt").expect("Couldn't read the file");
    let input = input.trim();
    let mut result: u64 = 0;
    let mut grid = [[0; LENGHT_X]; LENGHT_Y];
    for (a, line) in input.lines().enumerate() {
        for (b, character) in line.chars().enumerate() {
            match character {
                '@' => grid[a + 1][b + 1] = 1,
                '.' => (),
                c => panic!("Unknown char {}", c),
            }
        }
    }

    // for a in 1..(grid.len() - 1) {
    //     for b in 1..(grid[0].len() - 1) {
    //         if grid[a][b] == 1 {
    //             print!("@")
    //         } else {
    //             print!(".")
    //         }
    //     }
    //     print!("\n")
    // }

    for a in 1..(grid.len() - 1) {
        for b in 1..(grid[0].len() - 1) {
            if grid[a][b] == 0 {
                continue;
            }
            let mut count = 0;

            for r in (a - 1)..=(a + 1) {
                for c in (b - 1)..=(b + 1) {
                    if r == a && c == b {
                        continue;
                    }
                    count += grid[r][c];
                }
            }

            if count < 4 {
                result += 1;
            }
        }
    }

    println!("{}", result);
}
