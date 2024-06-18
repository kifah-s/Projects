

export const helloWorld = () => {
    console.log("hello world!!")
}

export const convertFileToBase64 = (file, onFinish) => {
    const reader = new FileReader();
    reader.readAsDataURL(file);
    reader.onload = () => {
        if (onFinish) {
            onFinish(reader.result)
        }
    }
}