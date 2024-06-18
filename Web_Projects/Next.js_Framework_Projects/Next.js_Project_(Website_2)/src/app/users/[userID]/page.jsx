export default async function UserDetails({ params }) {
  // * Wait for " 1 " seconds.
  await new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, 1000);
  });

  // console.log(params.userID);
  // * API.
  const response = await fetch(
    `https://jsonplaceholder.typicode.com/users/${params.userID}`
  );
  const user = await response.json();

  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">User Details</h1>
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
        <div className="userDetails">
          <h2>User Id: {user.id}</h2>
          <br />
          <h2>Name: {user.name}</h2>
          <br />
          <h2>User Name: {user.username}</h2>
          <br />
          <h3>User Address: {user.address.city}</h3>
        </div>
      </div>
    </>
  );
}
