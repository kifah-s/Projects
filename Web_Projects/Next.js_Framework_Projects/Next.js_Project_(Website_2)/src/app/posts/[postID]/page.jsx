export default async function PostDetails({ params }) {
  
  // * Wait for " 1 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 1000);
  });

  // console.log(params.postID);

  // * API.
  const response = await fetch(
    `https://jsonplaceholder.typicode.com/posts/${params.postID}`
  );
  const post = await response.json();

  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Posts Details</h1>
      </div>

      <div
        style={{
          display: "flex",
          justifyContent: "center",
          alignItems: "center",
          flexDirection: "column",
          width:"100%"
        }}
      >
        <div className="postDetails">
          <h2>User Id: {post.userId}</h2>
          <br />
          <h2>Post Id: {post.id}</h2>
          <br />
          <h2>Post Title: {post.title}</h2>
          <br />
          <h3>Post: {post.body}</h3>
        </div>
      </div>
    </>
  );
}
