import {BrowserRouter, Route, Routes} from "react-router-dom";
import Homepage from "./pages/Homepage.jsx";
import DetailsPage from "./pages/DetailsPage.jsx";
import MainLayout from "./layouts/MainLayout.jsx";
import NewDoctorPage from "./pages/NewDoctorPage.jsx";

function App() {

  return (
    <>
        <BrowserRouter>
            <Routes>
                <Route element={<MainLayout />}>
                    <Route index element={<Homepage />} />
                    <Route path="/details/:doctorId" element={<DetailsPage />} />
                    <Route path="/new" element={<NewDoctorPage />} />
                </Route>
            </Routes>
        </BrowserRouter>
    </>
  )
}

export default App
