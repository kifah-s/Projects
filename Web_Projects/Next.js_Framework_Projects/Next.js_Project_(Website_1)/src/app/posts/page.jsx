import Link from "next/link";

async function PostsPage() {
  const response = await fetch("https://jsonplaceholder.typicode.com/posts/1");
  const post = await response.json();
  return (
    <>
      <h1 className="centerElement">Posts Page</h1>
      <div className="post">
        <h3>User Id: {post.userId}</h3>
        <br />
        <h3>Title: {post.title}</h3>
        <br />
        <h3>Body: {post.body}</h3>
      </div>
    </>
  );
}

export default PostsPage;

//* By Default: React Server Component.
