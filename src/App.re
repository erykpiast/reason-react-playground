/* State declaration */
type state = {
  count: int,
};

/* Action declaration */
type action =
  | Click
  | Clear;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({count: state.count + 1})
    | Clear => ReasonReact.Update({count: 0})
    },

  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div>
      <button onClick=(_event => self.send(Click))>
        (ReasonReact.string("Click me!"))
      </button>
      <button onClick=(_event => self.send(Clear))>
        (ReasonReact.string("Clear!"))
      </button>
      <Component message={message} />
    </div>;
  },
};
