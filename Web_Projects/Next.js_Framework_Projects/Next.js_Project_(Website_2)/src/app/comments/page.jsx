import Link from "next/link";

export default async function Comments() {
  // * Wait for " 2 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 2000);
  });

  // * API.
  const response = await fetch("https://jsonplaceholder.typicode.com/comments");
  const comments = await response.json();

  const commentsJSX = comments.map((comment) => {
    return (
      <Link href={`/comments/${comment.id}`} style={{ width: "70%" }}>
        <div className="comments">
          <h2>Name: {comment.name}</h2>
          <br />
          <h2>Email: {comment.email}</h2>
          <br />
          <h3>Comment: {comment.body}</h3>
        </div>
      </Link>
    );
  });
  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Comments Page</h1>
      </div>

      {/* Comments */}
      <div
        style={{
          display: "flex",
          justifyContent: "center",
          alignItems: "center",
          flexDirection: "column",
        }}
      >
        {commentsJSX}
      </div>
    </>
  );
}
