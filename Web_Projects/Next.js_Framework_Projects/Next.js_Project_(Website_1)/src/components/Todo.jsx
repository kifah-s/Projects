"use client";

import { useState, useEffect } from "react";

function Todo() {
  const [todo, setTodo] = useState({});

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await fetch(
          "https://jsonplaceholder.typicode.com/todos/1"
        );
        const result = await response.json();

        setTodo(result);
      } catch (error) {
        console.error("Error fetching data:", error);
      }
    };

    fetchData();
  }, []);
  //* By Default: SSG(static side generation).

  return (
    <>
      <h3>- Todo Title: {todo.title}</h3>
    </>
  );
}

export default Todo;
