mod lc1;
fn main() {
    println!("Hello, world!");
    let v: Vec<i32> = vec![3, 2, 4];
    let x = lc1::ai::two_sum(v.clone(), 6);
    println!("{:?}", x);

    let v: Vec<i32> = vec![1, 2, 3, 5, 8];
    let x = lc1::ai::two_sum(v.clone(), 9);
    println!("{:?}", x);
}
