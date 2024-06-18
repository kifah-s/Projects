import Link from "next/link";

export default function Home() {
  return (
    <>
      <div style={{ display: "flex", justifyContent: "center" }}>
        <h1 className="pageName">Home Page</h1>
      </div>

      <div>
        <h1 className="home">Hello in Home Page</h1>
      </div>
    </>
  );
}
