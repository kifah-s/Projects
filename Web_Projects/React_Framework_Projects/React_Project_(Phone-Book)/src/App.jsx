import {BrowserRouter, Route, Routes} from "react-router-dom";
import MainPage from "./pages/MainPage.jsx";
import ContactDetails from "./pages/ContactDetails.jsx";
import MainLayout from "./layouts/MainLayout.jsx";

const App = () => {

    return (
        <>
            <BrowserRouter>
                <Routes>
                    <Route element={<MainLayout />}>
                        <Route index element={<MainPage />} />
                        <Route path={"/contacts/:contactId/details"} element={<ContactDetails />} />
                    </Route>
                </Routes>
            </BrowserRouter>
        </>
    )
}

export default App;