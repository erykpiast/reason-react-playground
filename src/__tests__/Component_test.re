/* Component_test.re */

open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let render = (message) =>
  Enzyme.shallow(<Component message />);

describe("Component", () => {
  open ExpectJs;

  test("test", () => {
    let text = render("Foo") |> Enzyme.Shallow.text;

    expect(text) |> toEqual("__Foo__");
  });
});