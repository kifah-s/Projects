import Link from "next/link";

export default async function Todos() {
  // * Wait for " 2 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 2000);
  });

  // * API.
  const response = await fetch("https://jsonplaceholder.typicode.com/todos");
  const todos = await response.json();

  const todosJSX = todos.map((todo) => {
    return (
      <Link href={`/todos/${todo.id}`} style={{ width: "70%" }}>
        <div className="todos">
          <h2>Todo Title: {todo.title}</h2>
          <br />
          <h3>Todo Completed: {todo.completed ? "True" : "False"}</h3>
          <br />
        </div>
      </Link>
    );
  });

  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Todos Page</h1>
      </div>

      {/* Todos */}
      <div
        style={{
          display: "flex",
          justifyContent: "center",
          alignItems: "center",
          flexDirection: "column",
        }}
      >
        {todosJSX}
      </div>
    </>
  );
}
