import Link from "next/link";

export const metadata = {
  title: "Todos",
};

function LayoutTodosPage({ children }) {
  return (
    <>
      <div
        style={{
          display: "flex",
          justifyContent: "space-around",
          alignItems: "center",
          margin: "10px",
        }}
      >
        <Link href="/todos">
          <h2>Todos</h2>
        </Link>

        <Link href="/todos/featuredTodos">
          <h2>Featured Todos</h2>
        </Link>
      </div>

      {children}
    </>
  );
}

export default LayoutTodosPage;
