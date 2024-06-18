export default async function PhotoDetails({ params }) {
  // * Wait for " 1 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 1000);
  });

  // console.log(params.photoID);

  // * API.
  const response = await fetch(
    `https://jsonplaceholder.typicode.com/photos/${params.photoID}`
  );
  const photo = await response.json();

  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Photo Details</h1>
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
        <div className="photoDetails">
          <h2>Album Id: {photo.albumId}</h2>
          <br />
          <h2>Image Id: {photo.id}</h2>
          <br />
          <h2>Photo Title: {photo.title}</h2>
          <br />
          <img src={photo.url} />
        </div>
      </div>
    </>
  );
}
