export default async function albumDetails({ params }) {
  // * Wait for " 1 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 1000);
  });

  //   console.log(params.albumID);

  // * API.
  const response = await fetch(
    `https://jsonplaceholder.typicode.com/albums/${params.albumID}`
  );
  const album = await response.json();

  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Album Details</h1>
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
        <div className="albumDetails">
          <h2>User Id: {album.userId}</h2>
          <br />
          <h2>Album Id: {album.id}</h2>
          <br />
          <h3>Album Title: {album.title}</h3>
        </div>
      </div>
    </>
  );
}
