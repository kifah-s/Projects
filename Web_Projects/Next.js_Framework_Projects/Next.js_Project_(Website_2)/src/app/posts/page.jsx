import Link from "next/link";

export default async function Posts() {
  // * Wait for " 2 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 2000);
  });

  // * API.
  const response = await fetch("https://jsonplaceholder.typicode.com/posts");
  const posts = await response.json();

  const postsJSX = posts.map((post) => {
    return (
      <Link href={`/posts/${post.id}`} style={{ width: "70%" }}>
        <div className="posts">
          <h2>Post Title: {post.title}</h2>
          <br />
          <h3>post: {post.body}</h3>
        </div>
      </Link>
    );
  });

  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Posts Page</h1>
      </div>

      {/* Posts */}
      <div
        style={{
          display: "flex",
          justifyContent: "center",
          alignItems: "center",
          flexDirection: "column",
        }}
      >
        {postsJSX}
      </div>
    </>
  );
}
