import {Link} from "react-router-dom";
import {Button} from "@nextui-org/react";

const DoctorListTile = ({doctor, onDelete}) => {
    return (

        <div className="bg-[#053f68] bg-opacity-40 p-3">
            <div className="flex justify-between">
                <div>
                    <h3 className="text-3xl">{doctor?.name}</h3>
                    <p>{doctor?.specialization}</p>
                </div>
                <div>
                    <Link to={`/details/${doctor?.id}`}>
                        <Button className="mr-3" color="primary">View</Button>
                    </Link>
                    <Button onClick={() => {
                        if (onDelete) {
                            onDelete(doctor.id);
                        }
                    }} color="danger">Delete</Button>
                </div>
            </div>
        </div>
    );
};

export default DoctorListTile;