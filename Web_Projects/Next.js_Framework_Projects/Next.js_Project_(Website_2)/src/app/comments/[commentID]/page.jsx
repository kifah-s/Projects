export default async function commentDetails({ params }) {
  // * Wait for " 1 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 1000);
  });

  //   console.log(params.commentID);

  // * API.
  const response = await fetch(
    `https://jsonplaceholder.typicode.com/comments/${params.commentID}`
  );
  const comment = await response.json();

  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Comment Details</h1>
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
        <div className="commentDetails">
          <h2>Post Id: {comment.postId}</h2>
          <br />
          <h2>Comment Id: {comment.id}</h2>
          <br />
          <h2>Name: {comment.name}</h2>
          <br />
          <h2>Email: {comment.email}</h2>
          <br />
          <h3>Comment: {comment.body}</h3>
        </div>
      </div>
    </>
  );
}
