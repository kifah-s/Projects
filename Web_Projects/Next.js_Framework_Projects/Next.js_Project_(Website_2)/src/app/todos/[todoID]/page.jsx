export default async function TodoDetails({ params }) {

  // * Wait for " 1 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 1000);
  });

  // console.log(params.todoID);

  // * API.
  const response = await fetch(
    `https://jsonplaceholder.typicode.com/todos/${params.todoID}`
  );
  const todo = await response.json();

  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Todo Details</h1>
      </div>

      <div
        style={{
          display: "flex",
          justifyContent: "center",
          alignItems: "center",
          flexDirection: "column",
          width: "100%",
        }}
      >
        <div className="todoDetails">
          <h2>User Id: {todo.userId}</h2>
          <br />
          <h2>Todo Id: {todo.id}</h2>
          <br />
          <h2>Todo Title: {todo.title}</h2>
          <br />
          <h3>Todo Completed: {todo.completed ? "True" : "False"}</h3>
        </div>
      </div>
    </>
  );
}
