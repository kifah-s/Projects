function ShowArticlePage(props) {
  console.log(props);

  return (
    <>
      <h1 className="centerElement">Show Article Page</h1>
      <h3 >Article Title: {props.params.articleTitle}</h3>
    </>
  );
}

export default ShowArticlePage;
