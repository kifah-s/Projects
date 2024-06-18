import {Link} from "react-router-dom";
import logo from "../assets/logo.png"
import ListOfDoctors from "../components/ListOfDoctors.jsx";
const Homepage = () => {
    return (
        <div className="flex flex-wrap">
            <div className="w-3/4">
                <ListOfDoctors />
            </div>
            <div className="w-1/4">
                <div className="flex justify-center py-10 mb-20">
                    <img className="w-3/4" src={logo} alt=""/>
                </div>
                <Link to="/new" >
                    <div className="p-5 bg-[#053f68] hover:bg-[#011a2c] text-white transition-background duration-700 text-center">New Doctor</div>
                </Link>
            </div>
        </div>
    );
};

export default Homepage;