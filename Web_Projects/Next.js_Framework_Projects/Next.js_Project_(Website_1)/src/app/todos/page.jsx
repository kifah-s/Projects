import Link from "next/link";
import Todo from "@/components/Todo";

async function TodosPage() {
  const response = await fetch("https://jsonplaceholder.typicode.com/todos/1", {
    // cache: "force-cache", //* By Default: SSG(static side generation).
    // cache: "no-store", //* SSR(server side rendering).
    // next: {
    //   revalidate: 60
    // } //* ISG(incremental static generation).
  });
  const todo = await response.json();
  //* By Default: SSG(static side generation).

  return (
    <>
      <h1 className="centerElement">Todos Page</h1>
      <div className="post">
        <h3>User Id: {todo.userId}</h3>
        <br />
        <h3>Todo Title: {todo.title}</h3>
      </div>
      <br />

      {/* <Todo /> */}
    </>
  );
}

export default TodosPage;

//* By Default: React Server Component.
