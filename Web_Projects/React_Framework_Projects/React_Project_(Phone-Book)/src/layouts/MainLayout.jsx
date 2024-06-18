import background from "../assets/background.jpg";
import {Outlet} from "react-router-dom";

const MainLayout = () => {
    return (
        <div className="h-screen flex" style={{
            background: `url(${background})`
        }}>
            <div className="m-auto bg-black bg-opacity-25 w-[90%] h-[80%] p-[30px]">
                <Outlet />
            </div>
        </div>
    );
};

export default MainLayout;