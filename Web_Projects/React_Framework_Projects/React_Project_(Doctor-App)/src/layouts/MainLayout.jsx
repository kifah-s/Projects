import bg from "../assets/bg.jpg"
import {Outlet} from "react-router-dom";
const MainLayout = () => {
    return (
        <div style={{
            backgroundImage: `url(${bg})`,
            backgroundRepeat: 'no-repeat',
            backgroundSize: "cover",
            backgroundPosition: "center center"
        }} className="h-screen w-full flex" >
            <div className="m-auto w-[90%] bg-[#011a2c] bg-opacity-90 h-[90%] overflow-auto text-white relative rounded-2xl">
                <Outlet />
            </div>
        </div>
    );
};

export default MainLayout;