fn escape_chars(input: &str) -> String {
    let mut output = String::new();
    
    for ch in input.chars() {
        match ch {
            '&' => output.push_str("&amp;"),
            '<' => output.push_str("&lt;"),
            '>' => output.push_str("&gt;"),
            _=> output.push(ch),
        }
    }
    output
}


fn main() {
    let input = "Bonnie & Bonkers found a > lying in wait, but crikey!, Steve came flying \
                    outta the bush and turned the > into a < before anyone knew what happened!";
    let escaped = escape_chars(input);
    println!("Original: {}", input);
    println!("Escapewd: {}", escaped);
}
