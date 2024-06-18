import Link from "next/link";

export default async function Albums() {
  // * Wait for " 2 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 2000);
  });

  // * API.
  const response = await fetch("https://jsonplaceholder.typicode.com/albums");
  const albums = await response.json();

  const albumsJSX = albums.map((album) => {
    return (
      <Link href={`/albums/${album.id}`} style={{ width: "70%" }}>
        <div className="albums">
          <h2>Album Title: {album.title}</h2>
          <br />
        </div>
      </Link>
    );
  });

  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Albums Page</h1>
      </div>

      {/* Albums */}
      <div
        style={{
          display: "flex",
          justifyContent: "center",
          alignItems: "center",
          flexDirection: "column",
        }}
      >
        {albumsJSX}
      </div>
    </>
  );
}
