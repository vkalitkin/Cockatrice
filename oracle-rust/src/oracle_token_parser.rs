#![feature(cstr_to_str)]

extern crate parser_combinators;
extern crate libc;
use parser_combinators::{choice, spaces, many, many1, sep_by, digit, char, Parser, ParserExt, ParseError, ParseResult};
use parser_combinators::char::{letter, string};
use std::ffi::CStr;

#[no_mangle]
pub extern fn add(lhs: u32, rhs: u32) -> u32 {
    lhs + rhs
}
/*
#[no_mangle]
pub extern fn parse(cinput: *const libc::c_char) {
  unsafe {
    let raw_input = CStr::from_ptr(cinput).to_str();
    parse_str(raw_input.unwrap());
    ()
  }
}
*/

fn parse_str(input: &str) -> Result<(), ParseError<char>> {
  let lc_input = input.to_lowercase();

  let puts = string("put").or(string("puts"));
  let a_an = char('a').or(string("an"));
  let begin_token = (puts, a_an);

  let digits = many1(digit()).map(|ds: String| ds);
  let pt_value = digits.or(char('X'));
  let pt = (pt_value, char('/'), pt_value);

  let parser = (begin_token, pt_value);
  let result = parser.parse(lc_input);
  result.map( |x| () )
}

#[test]
fn test_parse_card() {
  let result = parse_card("5 of Hearts");
  assert_eq!(result, Ok(((String::from("5"), " of ", "Hearts"), "")));
  assert!(parse_card("foo").is_err());
}

fn parse_card(input: &str) -> Result<((String, &str, &str), &str), ParseError<char>> {
  let value = many1(digit()).map(|ds: String| ds);
  let suit = choice([string("Hearts"), string("Spades"), string("Diamonds"), string("Clubs")]);
  let of = string(" of ");
  let mut card = (value, of, suit);
  let result = card.parse(input);
  result
}


