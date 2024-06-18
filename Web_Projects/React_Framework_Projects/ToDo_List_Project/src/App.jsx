import { useRef, useState } from "react";
import "./App.css";

function App() {
  // * States.
  const [todos, setTodos] = useState([]);

  const inputRef = useRef();

  // * Functions.
  const handleAddTodo = () => {
    const text = inputRef.current.value;
    // console.log(text);

    const newItem = { completed: false, text };

    setTodos([...todos, newItem]);

    inputRef.current.value = [""];
  };

  const handleItemDone = (index) => {
    const newTodos = [...todos];
    newTodos[index].completed = !newTodos[index].completed;
    setTodos(newTodos);
  };

  const handelDeleteItem = (index) => {
    const newTodos = [...todos];
    newTodos.splice(index, 1);
    setTodos(newTodos);
  };

  // console.log(todos);

  return (
    <div className="App">
      <div className="container">
        <h1>Todo List</h1>
        <ol>
          {todos.map(({ text, completed }, index) => {
            return (
              <div className="item">
                <li
                  className={completed ? "done" : ""}
                  key={index}
                  onClick={() => handleItemDone(index)}
                >
                  {text}
                </li>

                <span onClick={() => handelDeleteItem(index)}>X</span>
              </div>
            );
          })}
        </ol>
        <input type="text" placeholder="Enter item .." ref={inputRef} />
        <button onClick={handleAddTodo}>Add</button>
      </div>
    </div>
  );
}

export default App;
